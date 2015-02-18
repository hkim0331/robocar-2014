#!/usr/bin/env ruby
#-*- coding: utf-8 -*-
require 'sequel'
raise "usage:#{$0} file" unless ARGV.count==2
GRADING = Sequel.sqlite(ARGV[0])[:gradings]

File.foreach(ARGV[1]) do |line|
  next if line =~ /^#/
  g, p = line.split(/\s+/)
  next if p.nil?
  puts "#{g}: #{p}"
  GRADING.where(:gid => g.to_i).update(:l_ex => p.to_i)
end
