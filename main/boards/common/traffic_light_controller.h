#ifndef __TRAFFIC_LIGHT_CONTROLLER_H__
#define __TRAFFIC_LIGHT_CONTROLLER_H__

#include "mcp_server.h"
#include <driver/gpio.h>
#include <esp_log.h>

class TrafficLightController
{
private:
    bool red_state_ = false;
    bool yellow_state_ = false;
    bool green_state_ = false;
    gpio_num_t red_gpio_;
    gpio_num_t yellow_gpio_;
    gpio_num_t green_gpio_;

    void ConfigureGpio(gpio_num_t gpio_num)
    {
        gpio_config_t config = {
            .pin_bit_mask = (1ULL << gpio_num),
            .mode = GPIO_MODE_OUTPUT,
            .pull_up_en = GPIO_PULLUP_DISABLE,
            .pull_down_en = GPIO_PULLDOWN_DISABLE,
            .intr_type = GPIO_INTR_DISABLE,
        };
        ESP_ERROR_CHECK(gpio_config(&config));
        gpio_set_level(gpio_num, 1); // Initialize all LEDs to OFF (HIGH - inverted logic)
    }

public:
    TrafficLightController(gpio_num_t red_gpio, gpio_num_t yellow_gpio, gpio_num_t green_gpio)
        : red_gpio_(red_gpio), yellow_gpio_(yellow_gpio), green_gpio_(green_gpio)
    {
        // Configure all three GPIO pins
        ConfigureGpio(red_gpio_);
        ConfigureGpio(yellow_gpio_);
        ConfigureGpio(green_gpio_);

        auto &mcp_server = McpServer::GetInstance();

        // Get the state of all LEDs
        mcp_server.AddTool("self.traffic_light.get_state",
                           "Get the current state of all traffic light LEDs (red, yellow, green)",
                           PropertyList(),
                           [this](const PropertyList &properties) -> ReturnValue
                           {
                               cJSON *json = cJSON_CreateObject();
                               cJSON_AddBoolToObject(json, "red", red_state_);
                               cJSON_AddBoolToObject(json, "yellow", yellow_state_);
                               cJSON_AddBoolToObject(json, "green", green_state_);
                               return json;
                           });

        // Control red LED
        mcp_server.AddTool("self.traffic_light.set_red",
                           "Turn the red LED on or off",
                           PropertyList({Property("state", kPropertyTypeBoolean)}),
                           [this](const PropertyList &properties) -> ReturnValue
                           {
                               red_state_ = properties["state"].value<bool>();
                               gpio_set_level(red_gpio_, red_state_ ? 0 : 1); // Inverted: 0=ON, 1=OFF
                               return true;
                           });

        // Control yellow LED
        mcp_server.AddTool("self.traffic_light.set_yellow",
                           "Turn the yellow LED on or off",
                           PropertyList({Property("state", kPropertyTypeBoolean)}),
                           [this](const PropertyList &properties) -> ReturnValue
                           {
                               yellow_state_ = properties["state"].value<bool>();
                               gpio_set_level(yellow_gpio_, yellow_state_ ? 0 : 1); // Inverted: 0=ON, 1=OFF
                               return true;
                           });

        // Control green LED
        mcp_server.AddTool("self.traffic_light.set_green",
                           "Turn the green LED on or off",
                           PropertyList({Property("state", kPropertyTypeBoolean)}),
                           [this](const PropertyList &properties) -> ReturnValue
                           {
                               green_state_ = properties["state"].value<bool>();
                               gpio_set_level(green_gpio_, green_state_ ? 0 : 1); // Inverted: 0=ON, 1=OFF
                               return true;
                           });

        // Turn all LEDs off
        mcp_server.AddTool("self.traffic_light.turn_all_off",
                           "Turn off all traffic light LEDs",
                           PropertyList(),
                           [this](const PropertyList &properties) -> ReturnValue
                           {
                               red_state_ = false;
                               yellow_state_ = false;
                               green_state_ = false;
                               gpio_set_level(red_gpio_, 1);    // Inverted: 1=OFF
                               gpio_set_level(yellow_gpio_, 1); // Inverted: 1=OFF
                               gpio_set_level(green_gpio_, 1);  // Inverted: 1=OFF
                               return true;
                           });
    }
};

#endif // __TRAFFIC_LIGHT_CONTROLLER_H__
