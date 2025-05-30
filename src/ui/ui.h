#ifndef CGRA350_UI
#define CGRA350_UI
#pragma once

#include <imgui/imgui.h>
#include <imgui/backends/imgui_impl_glfw.h>
#include <imgui/backends/imgui_impl_opengl3.h>

#include <cuda_runtime.h>
#include <vector_types.h>
#include <string>
#include <glm/glm.hpp>

namespace CGRA350 {
    class AppContext;
}

class UI
{
private:
	static CGRA350::AppContext *m_app_context;
    static bool m_isChanging;

public:
	static void init(CGRA350::AppContext *app_context);
	static void render();
	static void destroy();

    static void SetIsChanging(bool isChanging);
    static bool GetIsChanging();
};

class GUIParam {
public:
    GUIParam();
    glm::vec3 GetDLight_Direction() const;

public:
    std::string device_name;

    int width = -1;
    int height = -1;

    ImVec2 needed_size;
    int frame;

    glm::vec3 cloud_position;
    float cloud_scale;
    float G;
    float alpha;
    int ms;

    bool render_surface = false;
    float IOR = 1.66;

    float tr = 1;

    float3 scatter_rate = { 1, 1, 1 };

    int env_map = 0;
    float env_exp = 1;

    float exposure = 1;

    float fps = 0;

    int toneType = 2;

    bool predict = true;

    bool mrpnn = true;

    bool pause = false;

    bool denoise = true;

    bool fsr = false;

    bool checkboard = false;

    float sharpness = 0.5;

    bool change_hdri = false;

    char saveName[100] = "Noname";
    bool need_save = false;

    bool inspector = false;

    std::string hdri_path = "";

    // --- Directional Light
    float dlight_azimuth, dlight_altitute;
    float3 dlight_color;
    float dlight_strength = 1.0f;  // light strength

    // --- Rain
    glm::vec3 rain_position;
    float rain_radius;
    float rain_sea_level;
    int raindrop_num;
    float raindrop_length;
    glm::vec3 raindrop_color;    
    float raindrop_min_speed;
    float raindrop_max_speed;

    // --- Postprocessing
    // Color Grading
    bool enableColorGrading;
    glm::vec3 colorFilter;

    // Dynamic Filter
    bool enableDynamicFilter;
    float contrast;
    float brightness;

    // Gaussian Blur
    bool enableGaussianBlur;
    glm::vec2 blurDirection;
    float blurWeight[5];
    glm::vec2 blurOffset[5];

    // Bloom Effect
    bool enableBloom;
    float bloomThreshold;
    float bloomIntensity;
};
#endif