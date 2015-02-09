#!/usr/bin/env ruby
#-*- coding: utf-8 -*-
require 'sequel'
grading = Sequel.sqlite("robocar-2014.db")[:gradings]

raise "usage:#{$0} file" unless ARGV.count == 1
File.foreach(ARGV[0]) do |line|
  next if line =~ /^#/
  g, p = line.split(/\s+/)
  next if p.nil?
  puts "#{g}: #{p}"
  grading.where(:gid => g.to_i).update(:l_ex => p.to_i)
end
