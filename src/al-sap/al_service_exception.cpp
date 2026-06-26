#include "al_service_exception.h"
#include <stdexcept>

// Constructor definition
AlServiceException::AlServiceException(const std::string& message, PrimitiveError error)
    : std::runtime_error(message), error(error) {
    if (message.empty()) {
        throw std::invalid_argument("AlServiceException: message cannot be empty");
    }
    if (static_cast<int>(error) < 0 || static_cast<int>(error) > static_cast<int>(PrimitiveError::FragmentOutOfOrder)) {
        throw std::invalid_argument("AlServiceException: invalid PrimitiveError value");
    }
}

// Method to get the PrimitiveReceipt value
PrimitiveError AlServiceException::getPrimitiveError() const {
    return error;
}