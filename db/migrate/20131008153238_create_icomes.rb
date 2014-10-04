class CreateIcomes < ActiveRecord::Migration
  def change
    create_table :icomes do |t|
      t.string :sid
      t.datetime :attend_at

      t.timestamps
    end
  end
end
