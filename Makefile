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

${OBJ}: src/config.h config.mk

config.h:
	cp config.def.h $@

${BUILD_DIR}: ${OBJ}
	${CC} -o $@ ${OBJ} ${LDFLAGS}

clean:
	rm -rf ${OBJ_DIR}

dist: clean
	mkdir -p archy-dwm_${VERSION}
	cp -R LICENSE Makefile README config.def.h config.mk \
		archy-dwm.1 drw.h util.h ${SRC} dwm.png transient.c archy-dwm_${VERSION}
	tar -cf archy-dwm_${VERSION}.tar archy-dwm_${VERSION}
	gzip archy-dwm_${VERSION}.tar
	rm -rf archy-dwm_${VERSION}

install: all
	mkdir -p ${DESTDIR}${PREFIX}/bin
	cp -f ${BUILD_DIR} ${DESTDIR}${PREFIX}/bin
	chmod 755 ${DESTDIR}${PREFIX}/bin/archy-dwm
	mkdir -p ${DESTDIR}${MANPREFIX}/man1
	sed "s/VERSION/${VERSION}/g" < archy-dwm.1 > ${DESTDIR}${MANPREFIX}/man1/archy-dwm.1
	chmod 644 ${DESTDIR}${MANPREFIX}/man1/archy-dwm.1

desktop:
	full_path=/usr/share/xsessions/archy-dwm.desktop
	mkdir -p /usr/share/xsessions
	cat <<EOT >> ${full_path}
	[Desktop Entry]
	Type=XSession
	Exec=/usr/local/bin/archy-dwm
	DesktopNames=archy-dwm
	Name=archy-dwm
	Comment="A dynamic window manager for X"

uninstall:
	rm -f ${DESTDIR}${PREFIX}/bin/archy-dwm \
		${DESTDIR}${MANPREFIX}/man1/archy-dwm.1

.PHONY: all options clean dist install uninstall
