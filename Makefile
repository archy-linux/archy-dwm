# dwm - dynamic window manager
# See LICENSE file for copyright and license details.

include config.mk

SRC = src/drw.c src/yo_dwm.c src/util.c
OBJ_DIR = build
OBJ = ${SRC:%.c=$(OBJ_DIR)/%.o}
BUILD_DIR = ${OBJ_DIR}/yo-dwm

all: options ${BUILD_DIR}

options:
	@echo yo-dwm build options:
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
	mkdir -p yo-dwm_${VERSION}
	cp -R LICENSE Makefile README config.def.h config.mk \
		yo-dwm.1 drw.h util.h ${SRC} dwm.png transient.c yo-dwm_${VERSION}
	tar -cf yo-dwm_${VERSION}.tar yo-dwm_${VERSION}
	gzip yo-dwm_${VERSION}.tar
	rm -rf yo-dwm_${VERSION}

install: all
	mkdir -p ${DESTDIR}${PREFIX}/bin
	cp -f ${BUILD_DIR} ${DESTDIR}${PREFIX}/bin
	chmod 755 ${DESTDIR}${PREFIX}/bin/yo-dwm
	mkdir -p ${DESTDIR}${MANPREFIX}/man1
	sed "s/VERSION/${VERSION}/g" < yo-dwm.1 > ${DESTDIR}${MANPREFIX}/man1/yo-dwm.1
	chmod 644 ${DESTDIR}${MANPREFIX}/man1/yo-dwm.1

desktop:
	full_path=/usr/share/xsessions/yo-dwm.desktop
	mkdir -p /usr/share/xsessions
	cat <<EOT >> ${full_path}
	[Desktop Entry]
	Type=XSession
	Exec=/usr/local/bin/yo-dwm
	DesktopNames=yo-dwm
	Name=yo-dwm
	Comment=Anas Elgarhy's dwm fork, with a lot of beautiful patches

uninstall:
	rm -f ${DESTDIR}${PREFIX}/bin/yo-dwm \
		${DESTDIR}${MANPREFIX}/man1/yo-dwm.1

.PHONY: all options clean dist install uninstall
