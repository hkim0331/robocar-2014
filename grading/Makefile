to-utf:
	for i in csv/*.csv; do \
		iconv -f SHIFT_JISX0213 -t UTF-8 $$i > utf8/`basename $$i`; \
	done

create:
	sqlite3 grading.db < create.sql

prep:
	ruby prep.rb utf8/*.csv

