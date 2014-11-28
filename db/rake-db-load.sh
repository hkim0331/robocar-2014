#!/bin/sh
gsed -i.bak 's/^    - $/    - 2014-11-26/' data.yml
rake db:load

