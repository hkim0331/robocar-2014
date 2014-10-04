class Student < ActiveRecord::Base
# http://stackoverflow.com/questions/10905870/how-to-user-has-secure-password-with-field-with-errors
#   attr_reader :password
#   attr_accessible :password
#   validates_confirmation_of :password
#   validates_presence_of :password, on: :create

  include ActiveModel::SecurePassword::InstanceMethodsOnActivation

  attr_accessible :sid, :uid, :name, :email, :group_id,
  	:password_digest, :password, :password_confirmation

  validates :sid, presence: true, uniqueness: true

  has_secure_password

  Admin = "hkimura"

# when rake db:seed, Admin is not exist.
#  AdminId = Student.find_by_sid(Student::Admin).id

end
