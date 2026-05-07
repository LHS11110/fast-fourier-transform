# Fast Fourier Transform (FFT)

## 📌 대략적인 설명 (Overview)

이 프로젝트는 쿨리-튜키(Cooley-Tukey) 알고리즘을 사용한 **고속 푸리에 변환 (Fast Fourier Transform, FFT)** 및 **역 고속 푸리에 변환 (Inverse FFT, IFFT)** 의 C++ 구현체입니다.

푸리에 변환은 시간이나 공간에 대한 함수를 주파수 성분으로 분해하는 수학적 기법입니다. 일반적인 이산 푸리에 변환(DFT)은 $O(n^2)$의 시간 복잡도를 가지지만, 고속 푸리에 변환(FFT)은 분할 정복(Divide and Conquer) 알고리즘을 통해 이를 $O(n \log n)$으로 크게 단축시킵니다. 신호 처리, 이미지 처리, 데이터 압축 등 다양한 분야에서 핵심적으로 사용됩니다.

본 구현체의 주요 특징은 다음과 같습니다:
- **Time Complexity (시간 복잡도):** $O(n \log n)$
- **Space Complexity (공간 복잡도):** $O(n)$
- **제약 사항:** 입력 데이터(배열)의 크기는 반드시 **2의 거듭제곱(Power of 2)** 이어야 합니다.

## 📂 디렉토리 구조 (Directory Structure)

- `include/fft.hpp`: FFT 클래스 선언 및 인터페이스
- `src/fft.cpp`: FFT 알고리즘 구현부
- `CMakeLists.txt`: CMake 빌드 설정 파일

## 🛠 빌드 방법 (How to Build)

이 프로젝트는 **CMake**를 사용하여 빌드합니다. 라이브러리 형태로 빌드되어 다른 프로젝트와 링크하여 사용할 수 있습니다.

### 요구 사항 (Requirements)
- C++17 이상을 지원하는 컴파일러
- CMake 3.10 이상

### 빌드 단계 (Build Steps)

터미널을 열고 다음 명령어를 순서대로 실행하여 라이브러리를 빌드하세요.

1. 빌드 결과를 저장할 디렉토리를 생성하고 해당 디렉토리로 이동합니다.
   ```bash
   mkdir build
   cd build
   ```

2. CMake를 실행하여 빌드 시스템 파일을 생성합니다.
   ```bash
   cmake ..
   ```

3. 코드를 컴파일하여 라이브러리(`libfft.a` 등)를 빌드합니다.
   ```bash
   make
   ```

빌드가 완료되면 `build` 디렉토리 내에 `libfft.a` (정적 라이브러리)가 생성됩니다. 이제 생성된 라이브러리를 사용자의 다른 프로젝트와 링크하여 FFT 및 IFFT 기능을 사용할 수 있습니다.

### 테스트 실행 (Running Tests)

작성된 테스트 코드를 실행하여 FFT와 IFFT의 동작을 검증할 수 있습니다. `build` 디렉토리 안에서 다음 명령어를 실행하세요.

```bash
# 생성된 테스트 실행 파일 직접 실행
./test_fft

# 또는 CTest를 사용하여 전체 테스트 실행
ctest --output-on-failure
```
