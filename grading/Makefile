SQL3=/usr/bin/sqlite3

create:
	cat create.sql | ${SQL3} robocar-2014.db

sid-jname-gid:
	./sid-jname-gid.rb

icome:
	cat icome.sql |sqlite3 development.sqlite3
	./icome.rb

p_ex:
	./personal_ex.rb

g_ex:
	./group_ex.rb

endterm: exam/all-by-yoshino.csv
	./exam.rb $<

l_ex: line-trace.txt
	./line-trace.rb $<

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

