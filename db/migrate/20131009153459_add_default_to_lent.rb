class AddDefaultToLent < ActiveRecord::Migration
  def change
    change_column :lents, :condition, :integer, default: Lent::Lent
  end
end
