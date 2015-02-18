#!/usr/bin/env ruby
require 'sequel'

GRADING = Sequel.sqlite(ARGV[0])[:gradings]

File.foreach("icome.txt") do |line|
  sid,icome = line.chomp.split(/\|/)
  puts "#{sid} #{icome}"
  GRADING.where(:sid => sid.to_i).update(:icome => icome.to_i)
end
