//
// Particle data transfromation
//   Redshift-space distortions with plane-parallel approximation
//

#include "transformation.h"

#include "particle.h"
#include <vector>

using namespace std;

void redshift_space_distortion(vector<ParticleData>& v, const float z, const float omega_m)
{
  const float a= 1.0f/(1.0f + z);
  const float omega_l= 1.0f - omega_m;
  const float H= 100.0*sqrt(omega_m/(a*a*a) + omega_l);

  const float fac= 1.0f/(a*H); // 1/H0 [hinv Mpc/(km/s)]

  for(vector<ParticleData>::iterator p= v.begin(); p != v.end(); ++p) {
    p->x[2] += fac*p->v[2];
  }
}
