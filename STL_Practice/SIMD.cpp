#include <immintrin.h> //SIMD 명령어 세트를 사용하기 위해 필요함.
#include <stdio.h>
int main() {
    int a[4] = { 1, 2, 3, 4 };
    int b[4] = { 5, 6, 7, 8 };
    int result[4];

    __m128i vec_a = _mm_loadu_si128((__m128i*)a); //메모리에서 벡터 데이터를 로드하는 함수
    __m128i vec_b = _mm_loadu_si128((__m128i*)b); 
    __m128i vec_result = _mm_add_epi32(vec_a, vec_b);// 두 벡터를 더 하는 함수

    _mm_storeu_si128((__m128i*)result, vec_result); //결과 벡터를 메모리에 저장하는 함수

    for (int i = 0; i < 4; i++) {
        printf("result[%d] = %d\n", i, result[i]);
    }

    //SIMD 벡터 연산은 하나의 명령어로 여러 데이터 요소를 동시에 처리합니다.
    //SSE(Streaming SIMD Extensions)기반의 SIMD 연산

    return 0;
}

/*
#include <stdio.h>
int main() {
    int a[4] = { 1, 2, 3, 4 };
    int b[4] = { 5, 6, 7, 8 };
    int result[4];

    for (int i = 0; i < 4; i++) {
        result[i] = a[i] + b[i];
        printf("%d ", result[i]);
    }

}
스칼라 연산 :한 번에 하나의 데이터 요소에 대한 계산을 수행하는 연산

스칼라 연산의 장점 및 효율적인 상황:

간단하고 직관적: 스칼라 연산은 코드가 간단하며 이해하기 쉽습니다. 개발 및 유지보수가 쉽습니다.

모든 하드웨어에서 동작: 스칼라 연산은 모든 종류의 하드웨어에서 동작하므로 이식성이 뛰어납니다.

단일 데이터 요소 처리: 하나의 데이터 요소에 대한 연산이 필요한 경우, 스칼라 연산은 간단하고 효과적일 수 있습니다.

SIMD 연산의 장점 및 효율적인 상황:

벡터화 연산: 여러 데이터 요소에 대한 동일한 연산을 동시에 수행하므로 대량 데이터 처리에 효과적입니다.

병렬 처리: SIMD 연산은 병렬 처리를 활용하여 작업을 가속화할 수 있습니다. 예를 들어, 그래픽 연산이나 과학 연산에서 유용합니다.

데이터 지역성 활용: 데이터 요소가 인접한 메모리 위치에 저장되어 있을 때 특히 효율적입니다.

성능 향상: 대부분의 모던 하드웨어는 SIMD 명령어 세트를 지원하므로 SIMD 연산을 사용하면 성능이 향상될 수 있습니다.

따라서 어떤 연산이 더 효율적인지 결정하려면 작업의 특성과 하드웨어 환경을 고려해야 합니다. 
데이터가 벡터화되어 있고 대량 처리가 필요한 경우에는 SIMD 연산이 효율적일 수 있지만, 단일 데이터 요소를 처리하거나 
코드가 단순한 경우에는 스칼라 연산이 더 적합할 수 있습니다. 종종 두 가지 연산을 조합하여 최적의 성능을 얻을 수도 있습니다.

*/
