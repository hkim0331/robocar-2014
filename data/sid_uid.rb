#!/usr/bin/env ruby
PREFIX = {'10'=>'j','11'=>'k', '12'=>'m', '13'=>'n', '14'=>'o'}

def sid2uid(sid)
  Dir.glob("/home/t/#{PREFIX[sid[0,2]] + sid[2,6]}*").first.sub(%r{/home/t/},'')
rescue
  sid
end

File.foreach("sids.txt") do |line|
  sid = line.chomp
  puts "#{sid} #{sid2uid(sid)}"
end

