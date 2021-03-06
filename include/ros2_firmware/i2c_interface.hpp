#pragma once

#include <string>

namespace ros2_firmware
{

class I2cInterface
{
public:
  I2cInterface(const std::string& i2c_bus);
  I2cInterface(const uint8_t& i2c_bus_number);
  int8_t open_bus();
  int8_t close_bus();
  int8_t set_device_id(uint8_t device_id);
  int8_t read_from_bus(uint8_t address, void* data, uint32_t count);
  int8_t read_from_bus(uint8_t device_id, uint8_t address,
                       void* data, uint32_t count);
  int8_t write_to_bus(const uint8_t address);
  int8_t write_to_bus(const uint8_t device_id, const uint8_t address);
  int8_t write_to_bus(const uint8_t address, void* data, uint32_t count);
  int8_t write_to_bus(const uint8_t device_id, const uint8_t address,
                      void* data, uint32_t count);
  bool is_available();
private:
  std::string i2c_bus_;
  int i2c_fd_;
};

}  // namespace ros2_firmware
