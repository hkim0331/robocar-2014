#!/usr/bin/env ruby
#-*- mode: ruby; coding: utf-8;-*-
# programmed by hkimura, 2015-02-06.

require 'cgi'
require 'sequel'

print <<EOH
content-type: text.html

<!DOCTYPE html>
<head>
<meta charset="utf-8">
<style>
.error { color:red; }
.point { width:3em; }
</style>
</head>
<body>
EOH
begin
  DS = Sequel.sqlite("robocar-2014.db")[:students]
  cgi = CGI.new

  if cgi.request_method =~ /GET/
    puts "<table><form method='post'>"
    DS.all.each do |s|
      print <<EOL
<tr><td>#{s[:sid]}<td>#{s[:jname]}<td>
<input type="hidden" name="id" value="#{s[:id]}">
<input class="point" name="point">
</tr>
EOL
    end
    puts "</table>"
    puts "<input type='submit' value='go'></form>"

  elsif cgi.request_method =~ /POST/
    puts "#{cgi['id']} #{cgi['point']}<br>"
  else
    raise "request method: #{cgi.request_method}"
  end

rescue => ex
  puts "<p class='error'>#{ex.message}</p>"
ensure
  print <<EOF
<hr>
programmed by hkimura, 2015-02-06.
</body>
</html>
EOF
end
