class WeeksChangeColumn < ActiveRecord::Migration
  def change
    change_column :weeks, :c1, :string
    change_column :weeks, :c2, :string
    change_column :weeks, :c3, :string
    change_column :weeks, :c4, :string
  end

end
