#include "leds.h"
#include "animations.h"
#include "patterns.h"
#include "timings.h"
#include "random.h"

// Animations
AnimationRandomReveal g_randomReveal;
AnimationFlashing g_flashPattern;
AnimationFillLeft g_fillLeft;
AnimationFillRight g_fillRight;
AnimationInstant g_fillInstant;
AnimationEdgeIn g_edgeIn;
AnimationFadeOut g_fadeOut;
AnimationFadeIn g_fadeIn;
AnimationCenterOut g_centerOut;
AnimationInstant g_instant;
AnimationSectionSlideLeft g_sectionSlideLeft;
AnimationSectionSlideRight g_sectionSlideRight;
AnimationSlideLeft g_slideLeft;
AnimationSlideRight g_slideRight;

Animation *g_animations[] = {
    &g_randomReveal, &g_flashPattern,
    &g_fillLeft, &g_fillRight,
    &g_edgeIn, &g_centerOut,
    &g_instant,
    &g_fadeOut, &g_fadeIn,
    &g_sectionSlideLeft, &g_sectionSlideRight,
    &g_slideLeft, &g_slideRight};
const uint8_t g_animationCount = sizeof(g_animations) / sizeof(Animation *);
Animation *g_currentAnimation = NULL;

// Patterns
SolidColorPattern g_solidColorPattern;
SolidColorPattern g_clearColorPattern;
RandomColorsPattern g_randomColorsPattern;

Pattern *g_patterns[] = {&g_solidColorPattern, &g_clearColorPattern, &g_randomColorsPattern};
const uint8_t g_patternCount = sizeof(g_patterns) / sizeof(Pattern *);
Pattern *g_currentPattern = &g_clearColorPattern;

// Timings
TimingConstant g_constantTiming;
TimingSpeedUp g_speedUp;
TimingSlowDown g_slowDown;

Timing *g_timings[] = {&g_constantTiming, &g_speedUp, &g_slowDown};
const uint8_t g_timingCount = sizeof(g_timings) / sizeof(Timing *);
Timing *g_currentTiming = NULL;

void NextScene()
{
  g_solidColorPattern.Color = RandomColor();

  Pattern *nextPattern = g_patterns[random(0, g_patternCount)];

  int i = 0;
  while (i < 10 && g_currentPattern == &g_clearColorPattern && nextPattern == &g_clearColorPattern)
  {
    nextPattern = g_patterns[random(0, g_patternCount)];
    i++;
  }

  // TODO : Remove this?
  // NOTE : Temporary implementation to prevent unlit/black colour being used in succession
  if (i >= 9)
  {
    nextPattern = &g_solidColorPattern;
    g_solidColorPattern.Color = CRGB::White;
  }

  g_currentPattern = nextPattern;
  g_currentTiming = g_timings[random(0, g_timingCount)];
  g_currentAnimation = g_animations[random(0, g_animationCount)];

  g_currentPattern->Reset();
  long totalSteps = g_currentAnimation->Begin(g_currentPattern);
  g_currentTiming->Reset(totalSteps);
}

void setup()
{
  Randomise();
  SetupLEDs();
  g_clearColorPattern.Color = CRGB::Black;
  NextScene();
}

void loop()
{
  if (g_currentAnimation->Step(g_currentPattern) == ANIMATION_STATE::COMPLETE)
  {
    NextScene();
    return;
  }
  g_currentTiming->Delay();
  g_currentPattern->NextState();
}
