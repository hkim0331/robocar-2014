module LentsHelper
	def delay?(lent)
		return false unless lent.willback_on
		if lent.back_on
			lent.back_on > lent.willback_on
		else
			Date.today > lent.willback_on
		end
	end
end
