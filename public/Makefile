HOST=robocar.melt.kyutech.ac.jp
BASE=/srv/robocar/public

all: install

install:
	rsync -av --exclude='*~' --exclude='Makefile' --exclude='#*' \
		--exclude='.DS_Store' --exclude='*.bak' \
		--exclude='*.ai' \
		. ${HOST}:${BASE}

2013-2014:
	gsed -i.bak \
		's/<title>robocar 2013<\/title>/<title>robocar 2014<\/title>/' \
		[a-zA-Z]*.html

clean:
	${RM} *~ *.bak */*.bak
