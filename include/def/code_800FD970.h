#pragma once

f32 Rand_Centered(void);
f32 Rand_Centered_Variable(u32* rndNum);
u32 Rand_Next(void);
u32 Rand_Next_Variable(u32* rndNum);
void Rand_Seed(u32 seed);
void Rand_Seed_Variable(u32* rndNum, u32 seed);
f32 Rand_ZeroOne(void);
f32 Rand_ZeroOne_Variable(u32* rndNum);
