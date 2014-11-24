HOST=robocar-2014.melt.kyutech.ac.jp
BASE=/srv/robocar-2014/public

all: install

install:
	rsync -av --exclude='*~' --exclude='Makefile' --exclude='#*' \
		--exclude='.DS_Store' --exclude='*.bak' \
		--exclude='*.ai' \
		--exclude='*.md' \
		. ${HOST}:${BASE}
	@echo "don't forget to chmod length/ for cgi call."

2013-2014:
	gsed -i.bak \
		's/<title>robocar 2013<\/title>/<title>robocar 2014<\/title>/' \
		[a-zA-Z]*.html

clean:
	${RM} *~ *.bak */*.bak
