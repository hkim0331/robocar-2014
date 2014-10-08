## 2014-10-08

````sh
$ RAILS_ENV=production rake db:seed
(in /srv/robocar-2014/releases/20141008003800)
seed Student
......................................................................................................................................................................................................................................................
seed Icome
rake aborted!
Errno::ENOENT: No such file or directory @ rb_sysopen - data/ucome.log
/srv/robocar-2014/releases/20141008003800/db/seeds.rb:20:in `foreach'
/srv/robocar-2014/releases/20141008003800/db/seeds.rb:20:in `<top (required)>'
Tasks: TOP => db:seed
````

## before 2014-10-01
ucome.log is mandatory to setup initial database, which is lacated at
robocar-2014:/srv/robocar-2014/private/ucome.log



