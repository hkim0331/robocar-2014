HOST=robocar.melt.kyutech.ac.jp
BASE=/srv/robocar/public

all: install

install:
	rsync -av --exclude='*~' --exclude='Makefile' --exclude='#*' \
		--exclude='.DS_Store' --exclude='*.bak' \
		--exclude='*.ai' \
		. ${HOST}:${BASE}

clean:
	${RM} *~ *.bak */*.bak
