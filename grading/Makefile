SQL3 = /usr/bin/sqlite3
DB   = grading.sqlite3

all: create sid-jname-gid icome p_ex g_ex endterm line-trace

create:
	cat create.sql | ${SQL3} ${DB}

sid-jname-gid:
	./sid-jname-gid.rb ${DB}

icome:
	cat icome.sql | sqlite3 development.sqlite3
	./icome.rb ${DB}

p_ex:
	./personal_ex.rb ${DB}

g_ex:
	./group_ex.rb ${DB}

endterm: exam/all-by-yoshino.csv
	./exam.rb ${DB} $<

line-trace: line-trace.txt
	./line-trace.rb ${DB} $<

######################

to-utf:
	for i in csv/*.csv; do \
		iconv -f SHIFT_JISX0213 -t UTF-8 $$i > utf8/`basename $$i`; \
	done

prep:
	ruby prep.rb utf8/*.csv

clean:
	${RM} *~

realclean:
	make clean
	${RM} robocar-2014.db

