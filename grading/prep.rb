#!/usr/bin/env ruby
# programmed by hkimura, 2015-02-06.

require 'sequel'

DS = Sequel.sqlite("robocar-2014.db")[:students]

while (arg = ARGV.shift)
  File.foreach(arg) do |line|
    next if line =~ /^#/
    dummy,jname,sid,rest = line.split(/,/,4)
    next if sid.empty?
    #    puts "#{jname}, #{sid}"
    DS.insert(:jname => jname, :sid =>sid)
  end
end
