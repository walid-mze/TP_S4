#ifndef METRIC_LOGGER_H
#define METRIC_LOGGER_H

#include <iostream>
#include <string>

template<typename T>
class MetricLogger {
public:
    static void logToStream(const T& obj, std::ostream& stream, const std::string& prefix = "") {
        if (!prefix.empty()) {
            stream << prefix << ": ";
        }
        stream << obj.getMetrics() << std::endl;
    }
};

#endif // METRIC_LOGGER_H 