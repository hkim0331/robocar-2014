#!/usr/bin/env ruby
Dir.glob("*.html") do |o|
  next unless o =~ /(\w+)_\d+\.html\Z/
  base=$1
  system("mv #{o} #{base}.html")
end
