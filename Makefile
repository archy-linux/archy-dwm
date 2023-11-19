# dwm - dynamic window manager
# See LICENSE file for copyright and license details.

include config.mk

SRC = src/drw.c src/archy_dwm.c src/util.c
OBJ_DIR = build
OBJ = ${SRC:%.c=$(OBJ_DIR)/%.o}
BUILD_DIR = ${OBJ_DIR}/archy-dwm

all: options ${BUILD_DIR}

options:
	@echo archy-dwm build options:
	@echo "CFLAGS   = ${CFLAGS}"
	@echo "LDFLAGS  = ${LDFLAGS}"
	@echo "CC       = ${CC}"

${OBJ_DIR}/%.o: %.c
	mkdir -p $(@D)
	${CC} -c ${CFLAGS} $< -o $@

${OBJ}: src/config/config.h config.mk

config.h:
	cp config.def.h $@

${BUILD_DIR}: ${OBJ}
	${CC} -o $@ ${OBJ} ${LDFLAGS}

clean:
	rm -rf ${OBJ_DIR}

dist: ${BUILD_DIR} archy-dwm.desktop
	mkdir -p archy-dwm_${VERSION}
	cp -R LICENSE README.md ${BUILD_DIR} ${OBJ_DIR}/archy-dwm.desktop archy-dwm.1 dwm.png archy-dwm_${VERSION}
	tar -cf archy-dwm_${VERSION}.tar archy-dwm_${VERSION}
	gzip archy-dwm_${VERSION}.tar
	rm -rf archy-dwm_${VERSION}
	mkdir -p dist
	mv archy-dwm_${VERSION}.tar.gz dist
	echo "The tarball is ready."
	printf "Tarball size: %s\n" $$(du -h dist/archy-dwm_${VERSION}.tar.gz | cut -f1)
	printf "Tarball hash: %s\n" $$(sha256sum dist/archy-dwm_${VERSION}.tar.gz)

install: all
	mkdir -p ${DESTDIR}${PREFIX}/bin
	cp -f ${BUILD_DIR} ${DESTDIR}${PREFIX}/bin
	chmod 755 ${DESTDIR}${PREFIX}/bin/archy-dwm
	mkdir -p ${DESTDIR}${MANPREFIX}/man1
	sed "s/VERSION/${VERSION}/g" < archy-dwm.1 > ${DESTDIR}${MANPREFIX}/man1/archy-dwm.1
	chmod 644 ${DESTDIR}${MANPREFIX}/man1/archy-dwm.1

archy-dwm.desktop:
	mkdir -p "$(OBJ_DIR)"
	echo "[Desktop Entry]" > "$(OBJ_DIR)/archy-dwm.desktop"
	echo "Type=XSession" >> "$(OBJ_DIR)/archy-dwm.desktop"
	echo "Exec=$(DESTDIR)$(PREFIX)/bin/archy-dwm" >> "$(OBJ_DIR)/archy-dwm.desktop"
	echo "DesktopNames=archy-dwm" >> "$(OBJ_DIR)/archy-dwm.desktop"
	echo "Name=archy-dwm" >> "$(OBJ_DIR)/archy-dwm.desktop"
	echo "Comment=\"A dynamic window manager for X\"" >> "$(OBJ_DIR)/archy-dwm.desktop"

desktop: archy-dwm.desktop
	mkdir -p ${DESTDIR}${PREFIX}/share/xsessions
	cp "$(OBJ_DIR)/archy-dwm.desktop" ${DESTDIR}${PREFIX}/share/xsessions/archy-dwm.desktop

uninstall:
	rm -f ${DESTDIR}${PREFIX}/bin/archy-dwm \
		${DESTDIR}${MANPREFIX}/man1/archy-dwm.1 \
		${DESTDIR}${PREFIX}/share/xsessions/archy-dwm.desktop

.PHONY: all options clean dist install uninstall
