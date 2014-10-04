class LentsChangeColumn < ActiveRecord::Migration
  def change
    change_column :lents, :lent_on, :date
  end

end
