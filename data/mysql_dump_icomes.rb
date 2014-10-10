#!/usr/bin/env ruby
require 'sequel'

DB = Sequel.connect("mysql2://hkimura:icome6@localhost/robocar_production")
DB[:icomes].where('attend_at > ?', '2014-10-01').each do |r|
  puts "#{r[:sid]} #{r[:attend_at]}"
end
