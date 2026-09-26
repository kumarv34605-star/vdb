# VDB — Requirements Specification

## 1. Project Overview

VDB (VishalDB) is a small relational database engine built from scratch for
learning database systems, operating systems, storage, concurrency,
networking, and reliability engineering.

VDB is an educational systems project. It is not intended to replace
production databases such as PostgreSQL or MySQL.

---

## 2. Goals

VDB should allow a user to:

- Start a database engine from the command line.
- Create tables.
- Insert records.
- Read records.
- Filter records using WHERE conditions.
- Update records.
- Delete records.
- Persist data to disk.
- Build and use an index.
- Execute transactions.
- Recover from a simulated crash.
- Communicate with the database over TCP.
- Support multiple concurrent clients.

The implementation should emphasize understanding of the underlying systems.

---

## 3. Non-Goals

VDB will not initially attempt to provide:

- Full SQL compatibility.
- Distributed database functionality.
- Replication.
- High availability.
- Production-grade security.
- Complex query optimization.
- A web interface.
- A PostgreSQL-compatible wire protocol.

These may be considered future extensions.

---

## 4. Functional Requirements

### FR-01 — Database Startup

The system shall start from the command line.

### FR-02 — Create Table

The system shall support creating a table with a defined schema.

### FR-03 — Insert

The system shall support inserting records into a table.

### FR-04 — Select

The system shall support retrieving records from a table.

### FR-05 — Persistence

Inserted data shall remain available after the database process is restarted.

### FR-06 — Filtering

The system shall support filtering records using WHERE conditions.

### FR-07 — Update

The system shall support modifying existing records.

### FR-08 — Delete

The system shall support deleting records.

### FR-09 — Indexing

The system shall support an index for efficient record lookup.

### FR-10 — Transactions

The system shall support:

- BEGIN
- COMMIT
- ROLLBACK

### FR-11 — Write-Ahead Logging

The system shall maintain a write-ahead log for transactional recovery.

### FR-12 — Crash Recovery

The system shall recover consistent database state after a simulated crash.

### FR-13 — TCP Server

The database shall support client connections over TCP.

### FR-14 — Concurrent Clients

The server shall support multiple concurrent clients.

---

## 5. Non-Functional Requirements

### NFR-01 — Correctness

Database operations shall produce deterministic and testable results.

### NFR-02 — Persistence

Committed data shall survive normal process termination and restart.

### NFR-03 — Reliability

The system shall detect and handle invalid operations without corrupting
database state.

### NFR-04 — Testability

Important components shall have automated tests.

### NFR-05 — Observability

The system shall provide useful information about:

- query latency
- storage operations
- cache behavior
- transaction activity
- recovery time

### NFR-06 — Performance

The project shall measure:

- insert throughput
- query latency
- index lookup latency
- full table scan latency
- recovery time

Performance measurements are for engineering comparison, not production
benchmark claims.

---

## 6. Initial Technology Stack

| Area | Technology |
|---|---|
| Language | C++17 |
| Build system | CMake |
| Platform | Linux / WSL2 |
| Version control | Git |
| Testing | GoogleTest |
| Interface | CLI |
| Storage | Local filesystem |
| Networking | TCP sockets |

Additional dependencies should be introduced only when they provide a clear
learning or engineering benefit.

---

## 7. Definition of Done

A feature is considered complete when:

1. The implementation works.
2. Error cases are handled.
3. Automated tests exist where appropriate.
4. Persistence is tested when applicable.
5. Documentation is updated.
6. The change is committed to Git.
7. The architecture documentation reflects the change when necessary.

---

## 8. Development Process

VDB will follow a lightweight iterative development process:

1. Requirements
2. Design
3. Implementation
4. Testing
5. Failure testing
6. Benchmarking
7. Documentation
8. Git commit
9. Review / retrospective
10. Next iteration

Each major feature should answer:

> Why does this exist?

> How does it work?

> What can fail?

> How do we test it?

> What happens underneath the abstraction?
