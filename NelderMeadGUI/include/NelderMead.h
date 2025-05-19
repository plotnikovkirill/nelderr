// NelderMead.h
#pragma once

#ifdef NELDERMEAD_EXPORTS
#define NELDERMEAD_API __declspec(dllexport)
#else
#define NELDERMEAD_API __declspec(dllimport)
#endif

extern "C" {
    // ��� ��� ������� �������
    typedef double (*ObjectiveFunction)(double*);

    // ��������� ���������
    typedef struct {
        double alpha;   // ����������� ���������
        double gamma;   // ����������� ����������
        double beta;    // ����������� ������
        double sigma;   // ����������� ����������
        double step;   // ��������� ���
        double tolerance; // �������� ���������
        int max_iterations; // ����. ����� ��������
    } NelderMeadParams;

    // ������� �����������
    NELDERMEAD_API void nelder_mead_optimize(
        ObjectiveFunction func,
        int dim,
        double* initial_point,
        double* result,
        NelderMeadParams* params
    );
}