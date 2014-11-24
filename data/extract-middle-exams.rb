#!/usr/bin/env ruby

require 'fileutils'

def usage
  print <<EOU
$ #{$0} src_dir dest_dir

extract the latest main.c from src_dir
saves it under dest_dir/group.txt
EOU
  exit(1)
end

usage unless ARGV.count == 2

Dir.glob("#{ARGV[0]}/*/201411{1,2}*").sort.each do |g|
  #puts g
  group = g.split(/\//)[1]
  FileUtils.cp(g, "#{ARGV[1]}/#{group}.txt")
end
