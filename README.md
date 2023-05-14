# JumpMap
> Overlap Event를 활용한 JumpMap Game 구현

## Tech Stack
<p>
<img src="https://img.shields.io/badge/unrealengine-0E1128?style=for-the-badge&logo=unrealengine&logoColor=white">
<img src="https://img.shields.io/badge/c++-00599C?style=for-the-badge&logo=cplusplus&logoColor=white">
</ p>

## 구현 목록

### 텔레포트 블록
![점프맵2](https://github.com/minhvvan/JumpMap/assets/59609086/f8ea846d-7b5b-4e0d-82cb-17a3f9cf89e2)
- Block의 Overlap Event가 발생하면 Overlap된 Player(Actor)를 정해진 위치로 텔레포트 시킨다.
- TeleportTo 함수를 이용하면 쉽게 구현할 수 있다.

### 밟으면 떨어지는 블록
![점프맵5](https://github.com/minhvvan/JumpMap/assets/59609086/6ea25dc9-9e75-4f78-ac7c-4128bb56622e)
- Block의 Overlap Event가 발생하면 Random한 시간이 지나고 떨어진다.
- Physics simulation을 활성화 하면 중력에 의해 자연스럽게 떨어진다. (Collision에 유의해야 한다.)

### 점프 함정 블록
![점프맵3](https://github.com/minhvvan/JumpMap/assets/59609086/48661e74-08fc-401a-a9a9-1a0f3a6724c2)
- Block의 Overlap Event가 발생하면 미리 설정한 방향으로 강력한 힘을 작용한다.
- 한번 밟고 나면 힘이 작용하는 방향을 바꿔 앞으로 날아 갈 수 있게 변경한다.

### 함정 트리거 볼륨
![점프맵1](https://github.com/minhvvan/JumpMap/assets/59609086/bbca893a-e9f0-4929-ad62-349495df57ed)
- 보이지 않지만 Overlap Event를 발생시킬 수 있는 Trigger Volume을 설정한다. 
- Overlap Event가 발생하면 왼쪽에서 거대한 구가 날아와 성공하지 못하게 방해한다.
- Level 단위의 Blueprint를 이용하여 쉽게 Event를 Control할 수 있다.

### 성공
![점프맵4](https://github.com/minhvvan/JumpMap/assets/59609086/013f1c65-85a2-4cca-9f74-96bdce600042)
- 보이지 않지만 Overlap Event를 발생시킬 수 있는 Trigger Volume을 설정한다. 
- Overlap Event가 발생하면 성공 UI를 VeiwPort에 추가하고 확인버튼을 클릭 시 게임을 종료한다.
