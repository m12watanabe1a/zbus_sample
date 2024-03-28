# Multi Publisher & Single Subscriber sample
Zbus multi Publisher & Single Subscriber samples.
Implementation itself is not actually subscriber, but lister.

```mermaid
sequenceDiagram
  participant P1 as Pub1
  participant P2 as Pub2
  participant S as Sub

  loop Every 2 seconds
    P1->>S: data: 1
    P2->>S: data: 2
  end
```

## Build
```bash
make build
```

## Run
```build
make run
```
