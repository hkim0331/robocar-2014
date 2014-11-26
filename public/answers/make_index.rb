#!/usr/bin/env ruby
IO.popen("ls -1 *.txt") do |p|
  p.readlines.each do |ans|
    ans = ans.chomp
    print <<EOL
<p><a href="#{ans}">#{ans}</a></p>
EOL
    end
end
