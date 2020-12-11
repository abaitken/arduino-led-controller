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
AnimationCenterOut g_centerOut;
AnimationInstant g_instant;

Animation *g_animations[] = {&g_randomReveal, &g_flashPattern, &g_fillLeft, &g_fillRight, &g_edgeIn, &g_centerOut, &g_instant, &g_fadeOut};
const uint8_t g_animationCount = sizeof(g_animations) / sizeof(Animation *);
Animation *g_currentAnimation = NULL;

// Patterns
SolidColorPattern g_solidColorPattern;
SolidColorPattern g_clearColorPattern;

Pattern *g_patterns[] = {&g_solidColorPattern, &g_clearColorPattern};
const uint8_t g_patternCount = sizeof(g_patterns) / sizeof(Pattern *);
Pattern *g_currentPattern = &g_clearColorPattern;

// Timings
TimingConstant g_constantTiming;

Timing *g_timings[] = {&g_constantTiming};
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

  if (i >= 9)
  {
    nextPattern = &g_solidColorPattern;
    g_solidColorPattern.Color = CRGB::White;
  }

  g_currentPattern = nextPattern;
  g_currentTiming = g_timings[random(0, g_timingCount)];
  g_currentAnimation = g_animations[random(0, g_animationCount)];

  g_currentPattern->Reset();
  g_currentAnimation->Begin(g_currentPattern);
  g_currentTiming->Reset();
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