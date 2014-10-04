class RecreateCars < ActiveRecord::Migration
  def up
    drop_table :cars
    create_table  :cars do |t|
      t.integer :condition

      t.timestamps
    end
  end

  def down
    drop_table :cars
    create_table :cars do |t|
      t.intger :status
      t.date   :lent_on
      t.date   :willback_on

      t.timestamps
    end
  end
end
