#ifndef RUPROXY_INFO
#define RUPROXY_INFO

#include <ctype.h>
#include <stdexcept>
#include <iostream>
#include <stdint.h>
#include <memory>

class RuproxyInfo
{
    private:
        uint16_t ruproxyId;
        uint64_t interval;

        uint16_t validateRuproxyId(uint16_t ruproxyId) const;
        uint64_t validateInterval(uint64_t interval) const;
    public:
        RuproxyInfo(uint16_t ruproxyId, uint64_t interval);
        ~RuproxyInfo() = default;

        RuproxyInfo(const RuproxyInfo& ruproxyObj) = delete;
        RuproxyInfo& operator=(const RuproxyInfo& ruproxyObj) = delete;

        RuproxyInfo(RuproxyInfo&& ruproxyObj);
        RuproxyInfo& operator=(RuproxyInfo&& ruproxyObj);

        friend std::ostream& operator<<(std::ostream& out, const RuproxyInfo &obj)
        {
	        out << "Ruproxy ID: " << obj.getRuproxyId() << " Interval: " << obj.getInterval() << std::endl;
	        return out;
        }

        const uint16_t getRuproxyId() const { return ruproxyId; }
        const uint64_t getInterval() const { return interval; }
};

#endif