#!/usr/bin/env ruby
# -*- mode:ruby; coding: utf-8 -*-
# programmed by hiroshi kimiura, 2014-11-24.

require 'cgi'
IDEAS = "./IDEAS.txt"

def show
  File.foreach(IDEAS) do |line|
    puts line
  end
end

def append(text)
  File.open(IDEAS,'a') do |f|
    return CGI::escapeHTML(text).gsub(/\r\n/,'<br>')
  end
end

cgi=CGI.new
print <<EOH
content-type: text/html

<head>
<meta charset='utf-8'>
</head>
<body style='font-family:sans-serif'>
<h2>長さを測るには？</h2>

EOH
begin
  if cgi.request_method=='GET'
    print <<EOF
<form method='post'>
<textarea name='text' style='width:400px;height:200px;'></textarea><br>
学生番号<input name='sid'><input type='submit'>
</form>
EOF
  elsif cgi.request_method=='POST'
    File.open(IDEAS,"a") do |f|
      f.print <<EOD
<p>
<b>From</b>: #{cgi['sid']}<br>
<b>Date</b>: #{Time.now}
</p>
<p>
#{append(cgi['text'])}
</p>
<hr>
EOD
    end
  end

  show()

ensure
  print <<EOF
<p><a href="./index.html">back</a></p>
<hr>
programmed by hkimura.
EOF
end
