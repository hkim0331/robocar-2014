#!/usr/bin/env dash
# -*- mode: Shell-script; coding: utf-8; -*-
#
# programmed by Hiroshi Kimura, 2012-01-12.
#
# = bump_version_model.sh
# プロジェクト内のファイルに一貫するバージョンナンバーを付与する。
#
# == usage
# 1. このファイルをプロジェクトフォルダにコピーし、
# 2. FILESに必要なファイルをスペースで区切ってリスト
# 3. do it.
#
# == updats
# 2012-01-15, updated.
# 2012-01-28, add comments.
# 2012-10-05, refine script.

if [ ! $# = 1 ]; then
	echo usage: $0 VERSION
	exit
fi
VERSION=$1
TODAY=`date +%Y-%m-%d`

# files to footprint version number.
FILES="upload/b upload/burn.sh"

# views
for i in ${FILES}; do
    sed -i.bak "s/^#[[:space:]]*VERSION:.*$/# VERSION: ${VERSION}/" "$i"
done

sed -i.bak "s/^version.*$/version ${VERSION}./" \
    "app/views/layouts/application.html.erb"

# add version number to *.html
# VERSION が コンマを一つしか含まないときだけ、アップデートする。
if [ $VERSION = "0.4" -o $VERSION = "0.5" -o $VERSION = "0.6" -o \
     $VERSION = "0.7" -o $VERSION = "0.8" -o $VERSION = "0.9" -o \
     $VERSION = "1.0" ]; then
    find ./ -name \*.html |
    	xargs sed -i.bak -E "s/^ *# *VERSION.*$/# VERSION: ${VERSION}/"
fi

# record the version number to file.
echo ${VERSION} > VERSION
