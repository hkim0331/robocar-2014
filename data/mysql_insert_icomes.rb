#!/usr/bin/env ruby
require 'sequel'

DB    = "mysql2://robocar_2014:r2014@localhost/robocar_2014_production"
ICOME = Sequel.connect(DB)[:icomes]

now = Time.now.strftime("%Y-%m-%d %H:%M:%S")
File.foreach("robocar_production.dump") do |line|
  sid, attend_at = line.chomp.split(/\s/,2)
  ICOME.insert(:sid =>sid, :attend_at => attend_at, 
               :created_at => now, :updated_at => now)

end
