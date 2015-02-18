#!/usr/bin/env ruby
#-*- coding: utf-8 -*-
require 'sequel'
raise "usage:#{$0} file" unless ARGV.count==2

GRADING = Sequel.sqlite(ARGV[0])[:gradings]

File.foreach(ARGV[1]) do |line|
  next if line =~ /^#/
  p,jname,sid,rest = line.split(/,/,4)
  next if p.empty?
  puts "#{sid} #{p}"
  GRADING.where(:sid => sid.to_i).update(:exam => p.to_i)
end
