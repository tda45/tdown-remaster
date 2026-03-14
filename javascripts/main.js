// TDown Remaster - Interactive JavaScript

document.addEventListener('DOMContentLoaded', function() {
    // Navigation Toggle
    const navToggle = document.querySelector('.nav-toggle');
    const navMenu = document.querySelector('.nav-menu');
    
    navToggle.addEventListener('click', function() {
        navMenu.classList.toggle('active');
    });
    
    // Smooth Scroll for Navigation Links
    const navLinks = document.querySelectorAll('.nav-link[href^="#"]');
    navLinks.forEach(link => {
        link.addEventListener('click', function(e) {
            e.preventDefault();
            const targetId = this.getAttribute('href').substring(1);
            const targetSection = document.getElementById(targetId);
            
            if (targetSection) {
                const offsetTop = targetSection.offsetTop - 80;
                window.scrollTo({
                    top: offsetTop,
                    behavior: 'smooth'
                });
            }
            
            // Close mobile menu if open
            navMenu.classList.remove('active');
        });
    });
    
    // Active Navigation Link on Scroll
    const sections = document.querySelectorAll('section[id]');
    const navLinksArray = Array.from(navLinks);
    
    function updateActiveNav() {
        const scrollY = window.pageYOffset;
        
        sections.forEach(section => {
            const sectionHeight = section.offsetHeight;
            const sectionTop = section.offsetTop - 100;
            const sectionId = section.getAttribute('id');
            
            if (scrollY > sectionTop && scrollY <= sectionTop + sectionHeight) {
                navLinksArray.forEach(link => {
                    link.classList.remove('active');
                    if (link.getAttribute('href') === `#${sectionId}`) {
                        link.classList.add('active');
                    }
                });
            }
        });
    }
    
    window.addEventListener('scroll', updateActiveNav);
    
    // Parallax Effect for Hero Section
    const hero = document.querySelector('.hero');
    const floatingIcons = document.querySelector('.floating-icons');
    
    window.addEventListener('scroll', function() {
        const scrolled = window.pageYOffset;
        const parallax = scrolled * 0.5;
        
        if (hero && floatingIcons) {
            floatingIcons.style.transform = `translateY(${parallax}px)`;
        }
    });
    
    // Typing Effect for Hero Title
    const heroTitle = document.querySelector('.hero-title');
    if (heroTitle) {
        const originalText = heroTitle.textContent;
        heroTitle.textContent = '';
        let charIndex = 0;
        
        function typeWriter() {
            if (charIndex < originalText.length) {
                heroTitle.textContent += originalText.charAt(charIndex);
                charIndex++;
                setTimeout(typeWriter, 100);
            }
        }
        
        setTimeout(typeWriter, 500);
    }
    
    // Intersection Observer for Animations
    const observerOptions = {
        threshold: 0.1,
        rootMargin: '0px 0px -50px 0px'
    };
    
    const observer = new IntersectionObserver(function(entries) {
        entries.forEach(entry => {
            if (entry.isIntersecting) {
                entry.target.style.opacity = '1';
                entry.target.style.transform = 'translateY(0)';
            }
        });
    }, observerOptions);
    
    // Observe Feature Cards
    const featureCards = document.querySelectorAll('.feature-card');
    featureCards.forEach((card, index) => {
        card.style.opacity = '0';
        card.style.transform = 'translateY(50px)';
        card.style.transition = `all 0.6s ease ${index * 0.1}s`;
        observer.observe(card);
    });
    
    // Observe Download Cards
    const downloadCards = document.querySelectorAll('.download-card');
    downloadCards.forEach((card, index) => {
        card.style.opacity = '0';
        card.style.transform = 'translateY(50px)';
        card.style.transition = `all 0.6s ease ${index * 0.1}s`;
        observer.observe(card);
    });
    
    // GitHub API for Stats
    async function fetchGitHubStats() {
        try {
            const response = await fetch('https://api.github.com/repos/tda45/tdown-remaster');
            const data = await response.json();
            
            document.getElementById('github-stars').textContent = data.stargazers_count || 0;
            document.getElementById('github-forks').textContent = data.forks_count || 0;
            
            // Get last commit date
            const commitsResponse = await fetch('https://api.github.com/repos/tda45/tdown-remaster/commits');
            const commitsData = await commitsResponse.json();
            if (commitsData.length > 0) {
                const lastCommit = new Date(commitsData[0].commit.author.date);
                const formattedDate = lastCommit.toLocaleDateString('tr-TR');
                document.getElementById('last-commit').textContent = formattedDate;
            }
        } catch (error) {
            console.error('GitHub API error:', error);
            document.getElementById('github-stars').textContent = 'N/A';
            document.getElementById('github-forks').textContent = 'N/A';
            document.getElementById('last-commit').textContent = 'N/A';
        }
    }
    
    fetchGitHubStats();
    
    // Theme Switcher
    const themeButtons = document.querySelectorAll('.theme-btn');
    themeButtons.forEach(button => {
        button.addEventListener('click', function() {
            const theme = this.getAttribute('data-theme');
            document.body.setAttribute('data-theme', theme);
            
            // Update active state
            themeButtons.forEach(btn => btn.classList.remove('active'));
            this.classList.add('active');
            
            // Save theme preference
            localStorage.setItem('theme', theme);
        });
    });
    
    // Load saved theme
    const savedTheme = localStorage.getItem('theme');
    if (savedTheme) {
        document.body.setAttribute('data-theme', savedTheme);
        const activeButton = document.querySelector(`[data-theme="${savedTheme}"]`);
        if (activeButton) {
            themeButtons.forEach(btn => btn.classList.remove('active'));
            activeButton.classList.add('active');
        }
    }
    
    // Search Functionality
    const searchTabs = document.querySelectorAll('.search-tab');
    const searchInput = document.getElementById('search-input');
    const searchBtn = document.getElementById('search-btn');
    const searchResults = document.getElementById('search-results');
    
    searchTabs.forEach(tab => {
        tab.addEventListener('click', function() {
            searchTabs.forEach(t => t.classList.remove('active'));
            this.classList.add('active');
        });
    });
    
    searchBtn.addEventListener('click', performSearch);
    searchInput.addEventListener('keypress', function(e) {
        if (e.key === 'Enter') {
            performSearch();
        }
    });
    
    async function performSearch() {
        const query = searchInput.value.trim();
        if (!query) return;
        
        const activeTab = document.querySelector('.search-tab.active').getAttribute('data-tab');
        searchResults.innerHTML = '<p class="search-placeholder">Aranıyor...</p>';
        
        try {
            let results = [];
            
            switch (activeTab) {
                case 'docs':
                    results = await searchDocumentation(query);
                    break;
                case 'issues':
                    results = await searchGitHubIssues(query);
                    break;
                case 'releases':
                    results = await searchReleases(query);
                    break;
            }
            
            displaySearchResults(results, activeTab);
        } catch (error) {
            searchResults.innerHTML = '<p class="search-placeholder">Arama sırasında hata oluştu.</p>';
        }
    }
    
    async function searchDocumentation(query) {
        // Mock documentation search
        return [
            { title: 'Kurulum', content: 'TDown Remaster kurulum talimatları...', url: '#install' },
            { title: 'Kullanım', content: 'TDown Remaster kullanım kılavuzu...', url: '#usage' },
            { title: 'Sorun Giderme', content: 'Sık karşılaşılan sorunlar...', url: '#troubleshooting' }
        ].filter(item => 
            item.title.toLowerCase().includes(query.toLowerCase()) || 
            item.content.toLowerCase().includes(query.toLowerCase())
        );
    }
    
    async function searchGitHubIssues(query) {
        const response = await fetch(`https://api.github.com/repos/tda45/tdown-remaster/issues?q=${query}`);
        const data = await response.json();
        return data.map(issue => ({
            title: issue.title,
            content: issue.body || '',
            url: issue.html_url,
            state: issue.state
        }));
    }
    
    async function searchReleases(query) {
        const response = await fetch('https://api.github.com/repos/tda45/tdown-remaster/releases');
        const data = await response.json();
        return data.filter(release => 
            release.name.toLowerCase().includes(query.toLowerCase()) ||
            release.body.toLowerCase().includes(query.toLowerCase())
        ).map(release => ({
            title: release.name,
            content: release.body || '',
            url: release.html_url,
            tag: release.tag_name
        }));
    }
    
    function displaySearchResults(results, type) {
        if (results.length === 0) {
            searchResults.innerHTML = '<p class="search-placeholder">Sonuç bulunamadı.</p>';
            return;
        }
        
        const html = results.map(result => `
            <div class="search-result-item">
                <h4><a href="${result.url}" target="_blank">${result.title}</a></h4>
                <p>${result.content.substring(0, 200)}...</p>
                ${result.state ? `<span class="search-result-state">${result.state}</span>` : ''}
                ${result.tag ? `<span class="search-result-tag">${result.tag}</span>` : ''}
            </div>
        `).join('');
        
        searchResults.innerHTML = html;
    }
    
    // Performance Metrics
    function calculatePerformanceMetrics() {
        // Load Speed
        const loadTime = performance.timing.loadEventEnd - performance.timing.navigationStart;
        document.getElementById('load-speed').textContent = `${(loadTime / 1000).toFixed(2)}s`;
        
        // Memory Usage (approximate)
        if (performance.memory) {
            const usedMemory = (performance.memory.usedJSHeapSize / 1048576).toFixed(2);
            document.getElementById('memory-usage').textContent = `${usedMemory}MB`;
        } else {
            document.getElementById('memory-usage').textContent = 'N/A';
        }
        
        // Core Web Vitals (mock values)
        document.getElementById('lcp').textContent = 'İyi';
        document.getElementById('fid').textContent = 'İyi';
        document.getElementById('cls').textContent = 'İyi';
    }
    
    // Calculate metrics after page load
    setTimeout(calculatePerformanceMetrics, 1000);
    
    // Visual Effects Controls
    const particlesToggle = document.getElementById('particles-toggle');
    const mouseToggle = document.getElementById('mouse-toggle');
    const patternSelect = document.getElementById('pattern-select');
    
    // Particle System
    class ParticleSystem {
        constructor(canvas) {
            this.canvas = canvas;
            this.ctx = canvas.getContext('2d');
            this.particles = [];
            this.isActive = true;
            this.init();
        }
        
        init() {
            this.resize();
            this.createParticles();
            this.animate();
            
            window.addEventListener('resize', () => this.resize());
        }
        
        resize() {
            this.canvas.width = window.innerWidth;
            this.canvas.height = window.innerHeight;
        }
        
        createParticles() {
            const particleCount = 50;
            for (let i = 0; i < particleCount; i++) {
                this.particles.push({
                    x: Math.random() * this.canvas.width,
                    y: Math.random() * this.canvas.height,
                    vx: (Math.random() - 0.5) * 0.5,
                    vy: (Math.random() - 0.5) * 0.5,
                    size: Math.random() * 3 + 1,
                    opacity: Math.random() * 0.5 + 0.2
                });
            }
        }
        
        animate() {
            if (!this.isActive) {
                this.ctx.clearRect(0, 0, this.canvas.width, this.canvas.height);
                requestAnimationFrame(() => this.animate());
                return;
            }
            
            this.ctx.clearRect(0, 0, this.canvas.width, this.canvas.height);
            
            this.particles.forEach(particle => {
                particle.x += particle.vx;
                particle.y += particle.vy;
                
                if (particle.x < 0 || particle.x > this.canvas.width) particle.vx *= -1;
                if (particle.y < 0 || particle.y > this.canvas.height) particle.vy *= -1;
                
                this.ctx.beginPath();
                this.ctx.arc(particle.x, particle.y, particle.size, 0, Math.PI * 2);
                this.ctx.fillStyle = `rgba(255, 0, 0, ${particle.opacity})`;
                this.ctx.fill();
            });
            
            requestAnimationFrame(() => this.animate());
        }
        
        toggle(active) {
            this.isActive = active;
        }
    }
    
    const particleCanvas = document.getElementById('particles-canvas');
    const particleSystem = new ParticleSystem(particleCanvas);
    
    particlesToggle.addEventListener('change', function() {
        particleSystem.toggle(this.checked);
    });
    
    // Mouse Trail Effect
    let mouseTrailEnabled = true;
    let mouseTrail = [];
    
    document.addEventListener('mousemove', function(e) {
        if (!mouseTrailEnabled) return;
        
        mouseTrail.push({ x: e.clientX, y: e.clientY, time: Date.now() });
        
        // Keep only recent positions
        mouseTrail = mouseTrail.filter(pos => Date.now() - pos.time < 1000);
        
        // Create trail effect
        if (mouseTrail.length > 1) {
            const trail = document.createElement('div');
            trail.style.position = 'fixed';
            trail.style.left = e.clientX + 'px';
            trail.style.top = e.clientY + 'px';
            trail.style.width = '10px';
            trail.style.height = '10px';
            trail.style.background = 'rgba(255, 0, 0, 0.3)';
            trail.style.borderRadius = '50%';
            trail.style.pointerEvents = 'none';
            trail.style.transition = 'opacity 1s ease-out';
            trail.style.zIndex = '9999';
            
            document.body.appendChild(trail);
            
            setTimeout(() => {
                trail.style.opacity = '0';
                setTimeout(() => trail.remove(), 1000);
            }, 100);
        }
    });
    
    mouseToggle.addEventListener('change', function() {
        mouseTrailEnabled = this.checked;
    });
    
    // Background Patterns
    patternSelect.addEventListener('change', function() {
        const pattern = this.value;
        const hero = document.querySelector('.hero');
        
        // Remove existing patterns
        hero.classList.remove('pattern-grid', 'pattern-dots', 'pattern-waves');
        
        if (pattern !== 'none') {
            hero.classList.add(`pattern-${pattern}`);
        }
    });
    
    // Newsletter Form
    const newsletterForm = document.querySelector('.newsletter-form');
    if (newsletterForm) {
        newsletterForm.addEventListener('submit', function(e) {
            e.preventDefault();
            const email = this.querySelector('input[type="email"]').value;
            
            // Show success message
            const successMessage = document.createElement('div');
            successMessage.textContent = 'Başarıyla abone oldunuz!';
            successMessage.style.cssText = `
                background: var(--accent);
                color: white;
                padding: 1rem;
                border-radius: 8px;
                margin-top: 1rem;
                text-align: center;
            `;
            
            this.appendChild(successMessage);
            this.reset();
            
            setTimeout(() => successMessage.remove(), 3000);
        });
    }
    
    // Stats Counter Animation
    const stats = document.querySelectorAll('.stat-number');
    const statsObserver = new IntersectionObserver(function(entries) {
        entries.forEach(entry => {
            if (entry.isIntersecting) {
                const target = entry.target;
                const finalValue = target.textContent;
                
                if (finalValue === '∞' || finalValue === 'N/A') {
                    if (finalValue === '∞') {
                        target.style.animation = 'pulse 2s infinite';
                    }
                } else {
                    const numericValue = parseInt(finalValue);
                    if (!isNaN(numericValue)) {
                        let currentValue = 0;
                        const increment = numericValue / 50;
                        
                        const updateCounter = () => {
                            currentValue += increment;
                            if (currentValue < numericValue) {
                                target.textContent = Math.floor(currentValue);
                                requestAnimationFrame(updateCounter);
                            } else {
                                target.textContent = numericValue;
                            }
                        };
                        
                        updateCounter();
                    }
                }
                
                statsObserver.unobserve(target);
            }
        });
    }, { threshold: 0.5 });
    
    stats.forEach(stat => statsObserver.observe(stat));
    
    // Add pulse animation
    const style = document.createElement('style');
    style.textContent = `
        @keyframes pulse {
            0%, 100% { transform: scale(1); }
            50% { transform: scale(1.1); }
        }
        
        .search-result-item {
            background: var(--bg-secondary);
            border: 1px solid var(--border);
            border-radius: 8px;
            padding: 1rem;
            margin-bottom: 1rem;
        }
        
        .search-result-item h4 {
            margin-bottom: 0.5rem;
        }
        
        .search-result-item a {
            color: var(--accent);
            text-decoration: none;
        }
        
        .search-result-item a:hover {
            text-decoration: underline;
        }
        
        .search-result-state,
        .search-result-tag {
            display: inline-block;
            padding: 0.2rem 0.5rem;
            border-radius: 4px;
            font-size: 0.8rem;
            margin-left: 0.5rem;
        }
        
        .search-result-state {
            background: var(--accent);
            color: white;
        }
        
        .search-result-tag {
            background: var(--bg-tertiary);
            color: var(--text-primary);
        }
        
        .pattern-grid::before {
            background-image: url('data:image/svg+xml,<svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 100 100"><defs><pattern id="grid2" width="20" height="20" patternUnits="userSpaceOnUse"><path d="M 20 0 L 0 0 0 20" fill="none" stroke="rgba(255,0,0,0.2)" stroke-width="1"/></pattern></defs><rect width="100" height="100" fill="url(%23grid2)"/></svg>');
        }
        
        .pattern-dots::before {
            background-image: url('data:image/svg+xml,<svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 100 100"><defs><pattern id="dots" width="30" height="30" patternUnits="userSpaceOnUse"><circle cx="15" cy="15" r="2" fill="rgba(255,0,0,0.2)"/></pattern></defs><rect width="100" height="100" fill="url(%23dots)"/></svg>');
        }
        
        .pattern-waves::before {
            background-image: url('data:image/svg+xml,<svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 100 100"><defs><pattern id="waves" width="100" height="20" patternUnits="userSpaceOnUse"><path d="M0 10 Q25 0 50 10 T100 10" stroke="rgba(255,0,0,0.2)" stroke-width="2" fill="none"/></pattern></defs><rect width="100" height="100" fill="url(%23waves)"/></svg>');
        }
    `;
    document.head.appendChild(style);
    
    // Loading Animation
    function showLoadingAnimation() {
        const loader = document.createElement('div');
        loader.className = 'loader';
        loader.innerHTML = `
            <div class="loader-spinner"></div>
            <div class="loader-text">🌙 TDown Remaster Yükleniyor...</div>
        `;
        loader.style.cssText = `
            position: fixed;
            top: 0;
            left: 0;
            width: 100%;
            height: 100%;
            background: var(--bg-primary);
            display: flex;
            flex-direction: column;
            justify-content: center;
            align-items: center;
            z-index: 9999;
            transition: opacity 0.5s ease;
        `;
        
        const spinnerStyle = document.createElement('style');
        spinnerStyle.textContent = `
            .loader-spinner {
                width: 50px;
                height: 50px;
                border: 3px solid var(--border);
                border-top: 3px solid var(--accent);
                border-radius: 50%;
                animation: spin 1s linear infinite;
                margin-bottom: 1rem;
            }
            
            .loader-text {
                color: var(--text-primary);
                font-size: 1.2rem;
                font-weight: 600;
            }
            
            @keyframes spin {
                0% { transform: rotate(0deg); }
                100% { transform: rotate(360deg); }
            }
        `;
        document.head.appendChild(spinnerStyle);
        
        document.body.appendChild(loader);
        
        setTimeout(() => {
            loader.style.opacity = '0';
            setTimeout(() => {
                loader.remove();
            }, 500);
        }, 1500);
    }
    
    // Show loading animation on page load
    showLoadingAnimation();
    
    // Console Easter Egg
    console.log('%c🌙 TDown Remaster', 'font-size: 20px; font-weight: bold; color: #ff0000;');
    console.log('%c🔥 Gece Modu Geliştirici', 'font-size: 16px; color: #ff3333;');
    console.log('%c💻 Modern Video İndirme Platformu', 'font-size: 14px; color: #ff6666;');
    console.log('%c🚀 https://github.com/tda45/tdown-remaster', 'font-size: 12px; color: #ff9999;');
});

// Performance Optimization
let ticking = false;
function requestTick(callback) {
    if (!ticking) {
        requestAnimationFrame(callback);
        ticking = true;
        setTimeout(() => { ticking = false; }, 100);
    }
}

// Smooth scroll performance
window.addEventListener('scroll', function() {
    requestTick(function() {
        // Scroll-based animations here
    });
});
