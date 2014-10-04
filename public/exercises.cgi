#!/usr/local/bin/ruby
# -*- mode: ruby; coding: utf-8 -*-
require 'cgi'
cgi=CGI.new

puts print <<EOH
content-type: text/html;charset='utf-8'

<!DOCTYPE html>
<html lang="ja">
<head>
<meta charset="utf-8" />
<link rel="stylesheet" href="stylesheets/screen.css" />
<title>robocar 2012:exercises</title>
</head>
<body>
<header>
情報処理応用 ー Robocar Programming
</header>
<h2>今日の課題</h2>
EOH

now=Time.now
if cgi['cmd'] =~ /\Aex\Z/
  answer = cgi['answer'].gsub(/'/,'"')
  File.open("exercises.log","a") do |fp|
    fp.puts "date: #{now}"
    fp.puts "sid: #{cgi['sid']}"
    fp.puts "ex: #{cgi['number']}"
    fp.puts "#{answer.gsub(/\r/,'')}"
    fp.puts "########"
  end
  print <<EOD
<p>#{now}, 学生番号 #{cgi['sid']}さんの回答を受け取りました。</p>
<p>受け取った回答は以下のとおり。</p>
<form>
<textarea rows='12' cols='60'>#{answer}</textarea>
</form>
EOD

else
  print <<EOF
<p>課題は授業中に出します。授業に集中しよう。</p>
<p>プログラムファイル提出の際は、エディタで作成し、
動作確認したものをコピー・ペーストする
(ちょくせつ下のエリアにタイプしようとしてもタブが入らないよ)。
<form method='post'>
<input type='hidden' name='cmd' value='ex'>
問題番号:<input name='number'><br/>
学生番号(もしくはグループ番号):<input name='sid'>(半角数字で)<br/>
<textarea rows='12' cols='60' name='answer'></textarea><br/>
<input type='submit'>
</form>
EOF
end

# footer
  print <<EOF
<p><a href="index.html">back</a></p>
<footer>
Copyright &copy; 2012 Hiroshi Kimura.
</footer>
</body>
</html>
EOF
