class AddCondtionToLent < ActiveRecord::Migration
  def change
    add_column :lents, :condition, :integer
  end
end
