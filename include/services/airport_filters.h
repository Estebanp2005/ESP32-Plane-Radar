#pragma once

namespace services::airport_filters {

/** Load saved airport type filters from NVS, or use defaults.
 *  Call once early, before the WiFi setup portal runs. */
void init();

// Getters — used by runway_overlay and radar display
bool showLargeAirports();
bool showMediumAirports();
bool showSmallAirports();
bool showMilitaryAirports();

/** Parse portal strings (checkbox values), validate, persist to NVS.
 *  Called by wifi_setup.cpp when user saves the portal form. */
bool saveFromPortal(const char* large, const char* medium,
                    const char* small, const char* military);

/** Clear stored filters when WiFi is reset (revert to defaults). */
void clear();

}  // namespace services::airport_filters