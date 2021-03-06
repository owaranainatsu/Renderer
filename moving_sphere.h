#ifndef MOVING_SPHERE_H
#define MOVING_SPHERE_H
#include "constant.h"
#include "hittable.h"

class moving_sphere : public hittable {
    public:
        moving_sphere() {}
        moving_sphere(point3 cen0, point3 cen1, double t0, double t1, double r, shared_ptr<material> m)
                    :center0(cen0), center1(cen1), time0(t0), time1(t1), radius(r), mat_ptr(m) {}
    virtual bool hit(const ray& r, double t_min, double t_max, hit_record& rec) const override;
    point3 center(double time) const;

    public:
        point3 center0, center1;
        double time0, time1;
        double radius;
        shared_ptr<material> mat_ptr;
};
point3 moving_sphere::center(double time) const {
    return center0 + ((time - time0) / (time1 - time0)) * (center1 - center0);
}
#endif