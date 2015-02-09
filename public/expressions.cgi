#!/usr/bin/env ruby
#-*- mode: ruby; coding: utf-8; -*-

require 'cgi'

EXPRESSIONS = "2014-expressions.html"
cgi = CGI.new

print <<EOH
content-type: text/html

<!DOCTYPE "html">
<html>
<head>
<link charset="utf-8">
<title>robocar-2014</title>
<style>
body { font-family: sans-serif;}
h2 {color: green;}
li {color: blue;}
</style>
</head>
<body>
EOH

begin
  if (cgi.request_method=~/GET/)
    print <<EOD
<h2>情報応用（ロボカー）2014の感想、未来の受講生へのアドバイス</h2>

<p>修正なしで来年度以降の受講生に見せます。
授業の改善に役立てます。
新しい投稿は<a href=#bottom>一番下</a>にくっつきます。
</p>

<form method="post">
<textarea name="e" cols="60" rows="10">
</textarea><br>
<input type="submit" value="送信">
</form>

<hr>
<h2>EXPRESSIONS 2014</h2>
EOD
    File.foreach(EXPRESSIONS) do |line|
      puts line
    end

  elsif (cgi.request_method =~ /POST/)
    File.open(EXPRESSIONS,"a") do |fp|
      fp.puts "<li>#{Time.now}</li>"
      fp.puts CGI::escapeHTML(cgi['e'])
      fp.puts "<hr>"
    end

    print <<EOC
<p><a href="expressions.cgi">ご苦労さんでした。</a></p>
EOC
  else
    raise "unknown request method: #{cgi.request_method}"
  end

ensure
  print <<EOF
</ol>
<p><a name='bottom'>&nbsp;</a></p>
<hr>
programmed by hkimura, 2015-02-04.
EOF
end
