#include "Ruproxy.hpp"

RuproxyInfo::RuproxyInfo(uint16_t ruproxyId, uint64_t interval) :
    ruproxyId(validateRuproxyId(ruproxyId)),
    interval(validateInterval(interval)) 
    { }

RuproxyInfo::RuproxyInfo(RuproxyInfo&& ruproxyObj):
    ruproxyId(ruproxyObj.getRuproxyId()),
    interval(ruproxyObj.getInterval())
    { }

RuproxyInfo& RuproxyInfo::operator=(RuproxyInfo&& ruproxyObj)
{
    if (&ruproxyObj == this)
			return *this;

		ruproxyId = ruproxyObj.ruproxyId;
		interval = ruproxyObj.interval;

		return *this;
}

uint16_t RuproxyInfo::validateRuproxyId(uint16_t ruproxyId) const {
    if ( !( (ruproxyId >=1 && ruproxyId <=32) ) )
        throw std::invalid_argument("Invalid ruproxy id received.");
    
    return ruproxyId;
}

uint64_t RuproxyInfo::validateInterval(uint64_t interval) const {
    if ( !( interval == 300 || interval == 900 || 
            interval == 1800 || interval == 3600 || 
            interval == 21600 || interval == 43200 || interval == 86400) )
        throw std::invalid_argument("Invalid interval received.");

    return interval;
}


int main() {

    std::unique_ptr<RuproxyInfo> objInfo {new RuproxyInfo{1, 300}};
    
    std::cout << info ;

    return 0;

}