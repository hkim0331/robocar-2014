#!/usr/bin/env ruby
#-*- coding: utf-8 -*-
require 'sequel'
grading = Sequel.sqlite("robocar-2014.db")[:gradings]

raise "usage:#{$0} file" unless ARGV.count == 1
File.foreach(ARGV[0]) do |line|
  next if line =~ /^#/
  p,jname,sid,rest = line.split(/,/,4)
  next if p.empty?
  grading.where(:sid => sid.to_i).update(:exam => p.to_i)
end
