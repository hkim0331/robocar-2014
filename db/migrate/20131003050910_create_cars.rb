class CreateCars < ActiveRecord::Migration
  def change
    create_table :cars do |t|
      t.integer :status
      t.date :lent_on
      t.date :will_back

      t.timestamps
    end
  end
end
